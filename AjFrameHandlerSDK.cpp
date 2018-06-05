#include "AjFrameHandlerSDK.h"

int AjFrameHandlerSDK::VideoCallback(
    char *frame, int len, int isKey, double timestamp,
    unsigned long frameIndex, unsigned long keyFrameIndex,
    void *context)
{
    AjFrameHandlerSDK *self = (AjFrameHandlerSDK *)context;
    return self->handler->sendVideo(frame, len, timestmap, isKey);
    //return QN_SUCCESS;
}

int AjFrameHandlerSDK::AudioCallback(
    char *frame, int len, double timestamp,
    unsigned long frameIndex, void *context)
{
    AjFrameHandlerSDK *self = (AjFrameHandlerSDK *)context;
    return self->handler->sendAudio(frame, len, timestamp);
    //return QN_SUCCESS;
}

AjFrameHandlerSDK::AjFrameHandlerSDK() {
    inited = init();
    audioEnabled = audio();
    started = false;
}

bool AjFrameHandlerSDK::audio() {
    AudioConfig audioConfig;
    dev_sdk_get_AudioConfig(&audioConfig);
    return audioConfig.audioEncode.enable == 1;
}

int AjFrameHandlerSDK::init() {
    return dev_sdk_init(DEV_SDK_PROCESS_APP);
}

bool AjFrameHandlerSDK::start() {
    if (inited) {
        dev_sdk_start_video(0, 0, AjFrameHandlerSDK::VideoCallback, this);
        if (audioEnabled) {
            dev_sdk_start_audio_play(AUDIO_TYPE_AAC);
            dev_sdk_start_audio(0, 1, audio_callback, NULL);
            started = true;
        }
    }
    return started;
}

bool AjFrameHandlerSDK::stop() {
    if (started) {
        dev_sdk_stop_video(0, 1);
        if (audioEnabled) {
            dev_sdk_stop_audio(0, 1);
            dev_sdk_stop_audio_play();
        }
        dev_sdk_release();
        started = false;
    }
    return started;
}
