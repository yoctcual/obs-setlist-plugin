#include <obs-module.h>
#include "setlist-source.hpp"

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("setlist_plugin", "en-US")

bool obs_module_load(void) {
    obs_register_source(&setlist_source_info);
    blog(LOG_INFO, "Setlist Plugin Loaded!");
    return true;
}
