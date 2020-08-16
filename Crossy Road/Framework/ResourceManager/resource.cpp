#include "resource.h"
resource::resource()
    : fonts("fonts")
    , textures("textures")
    , sound_buffers("sounds")
{}
resource& resource::get()
{
    static resource storage;
    return storage;
}
