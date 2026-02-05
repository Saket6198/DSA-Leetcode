#include<bits/stdc++.h>
using namespace std;

// abstract class for Observer

class ISubscriber {
public: 
    virtual void update() = 0;
    ~ISubscriber() {}
};

// abstract class for subject(observable)

class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscriber() = 0;
    virtual ~IChannel() {}
};

class Channel : public IChannel {
private:
    string ChannelName;
    vector<ISubscriber*> subscribers;
    string latestVideo;
public:
    Channel(const string& name){
        this->ChannelName = name; 
    }

    void subscribe(ISubscriber* subscriber) override {
        if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
            subscribers.push_back(subscriber);
        return;
    }

    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notifySubscriber() override {
        for (auto& subscriber : subscribers) {
            subscriber->update();
        }
    }

    void uploadVideo(const string& videoTitle) {
        latestVideo = videoTitle;
        cout << "New video uploaded: " << latestVideo << " on channel: " << ChannelName << endl;
        notifySubscriber();
    }

    string getVideoData(){
        return "Checkout our latest video: " + latestVideo + " on channel: " + ChannelName + "\n";
    }
};

class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;
public:
    Subscriber(const string& name, Channel* channel){
        this->name = name;
        this->channel = channel;

    }
    void update() override {
        cout << "Hey " << name << "," << this->channel->getVideoData();
    }
};


int main() {
    Channel* channel1 = new Channel("TheRadBrad");
    Channel* channel2 = new Channel("DDOD");
    Subscriber* subscriber1 = new Subscriber("Saket", channel1);
    Subscriber* subscriber2 = new Subscriber("Sahil", channel1);
    channel1->subscribe(subscriber1);
    channel1->subscribe(subscriber2);
    channel1->uploadVideo("The Last of Us Part 1");
    channel1->unsubscribe(subscriber2);
    channel1->uploadVideo("The Last of Us Part 2");

}

// Output:
// New video uploaded: The Last of Us Part 1 on channel: TheRadBrad
// Hey Saket,Checkout our latest video: The Last of Us Part 1 on channel: TheRadBrad
// Hey Sahil,Checkout our latest video: The Last of Us Part 1 on channel: TheRadBrad
// New video uploaded: The Last of Us Part 2 on channel: TheRadBrad
// Hey Saket,Checkout our latest video: The Last of Us Part 2 on channel: TheRadBrad
