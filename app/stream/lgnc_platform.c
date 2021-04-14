#include "platform.h"

bool platform_check_lgnc(PPLATFORM_INFO pinfo)
{
    pinfo->valid = true;
    pinfo->vrank = 9;
    pinfo->arank = 29;
    pinfo->vindependent = false;
    pinfo->aindependent = false;
    pinfo->maxBitrate = 40000;
    return true;
}

extern AUDIO_RENDERER_CALLBACKS audio_callbacks_lgnc;
extern DECODER_RENDERER_CALLBACKS decoder_callbacks_lgnc;

PLATFORM_SYMBOLS platform_lgnc = {
    true,
    NULL,
    &platform_check_lgnc,
    NULL,
    &audio_callbacks_lgnc,
    &decoder_callbacks_lgnc,
    NULL,
    NULL,
};