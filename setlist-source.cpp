#include "setlist-source.hpp"
#include <graphics/graphics.h>

struct setlist_data {
    std::string text;
    uint32_t color;
    bool transparent;
};

static const char *setlist_get_name(void *) {
    return "Setlist Source";
}

static void *setlist_create(obs_data_t *settings, obs_source_t *source) {
    setlist_data *data = new setlist_data;
    data->text = obs_data_get_string(settings, "text");
    data->color = (uint32_t)obs_data_get_int(settings, "color");
    data->transparent = obs_data_get_bool(settings, "transparent");
    return data;
}

static void setlist_destroy(void *data) {
    delete static_cast<setlist_data *>(data);
}

static void setlist_update(void *data, obs_data_t *settings) {
    auto *d = static_cast<setlist_data *>(data);
    d->text = obs_data_get_string(settings, "text");
    d->color = (uint32_t)obs_data_get_int(settings, "color");
    d->transparent = obs_data_get_bool(settings, "transparent");
}

static obs_properties_t *setlist_properties(void *) {
    obs_properties_t *props = obs_properties_create();

    obs_properties_add_text(props, "text", "Setlist Text", OBS_TEXT_MULTILINE);
    obs_properties_add_color(props, "color", "Text Color");
    obs_properties_add_bool(props, "transparent", "Transparent Background");

    return props;
}

static void setlist_render(void *data, gs_effect_t *) {
    auto *d = static_cast<setlist_data *>(data);

    if (!d->transparent)
        gs_clear(GS_CLEAR_COLOR, (uint32_t[]){0, 0, 0, 255}, 0.0f, 0);

    obs_source_text_draw(d->text.c_str(), d->color);
}

obs_source_info setlist_source_info = {
    .id = "setlist_source",
    .type = OBS_SOURCE_TYPE_INPUT,
    .output_flags = OBS_SOURCE_VIDEO,
    .get_name = setlist_get_name,
    .create = setlist_create,
    .destroy = setlist_destroy,
    .update = setlist_update,
    .get_properties = setlist_properties,
    .video_render = setlist_render
};
