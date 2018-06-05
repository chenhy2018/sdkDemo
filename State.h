class State {
public:
    virtual void create() = 0;
    virtual void destory() = 0;
    virtual void sendVideo() = 0;
    virtual void sendAudio() = 0;

protected:
    virtual void changeState() = 0;
}
