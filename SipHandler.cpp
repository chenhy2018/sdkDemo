#include "SipHandler.h"

void initSipLock()
{
    gSipLock.status = 0;
    pthread_mutex_init(&gSipLock.regStatusLock, NULL);
}

void unlockCall()
{
    pthread_mutex_lock(&gSipLock.regStatusLock);
    gSipLock.status = 0;
    pthread_mutex_unlock(&gSipLock.regStatusLock);
}

int getSipStatus(void)
{
    int status = 0;
    pthread_mutex_lock(&gSipLock.regStatusLock);
    status = gSipLock.status;
    pthread_mutex_unlock(&gSipLock.regStatusLock);
    return status;
}

int lockCall(void)
{
    pthread_mutex_lock(&gSipLock.regStatusLock);
    if (gSipLock.status == 1) {
        pthread_mutex_unlock(&gSipLock.regStatusLock);
        return 488;
    }
    gSipLock.status = 1;
    pthread_mutex_unlock(&gSipLock.regStatusLock);

    return OK;
}

void SipHandler::OnCallStateChange(
    int callId, SipInviteState state, SipAnswerCode code)
{
    if (state == INV_STATE_CONFIRMED) {
        handler->open()
    } else if (state == INV_STATE_DISCONNECTED) {
        handler->close()
    }
}
