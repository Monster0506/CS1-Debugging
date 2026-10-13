// Observer pattern with a signup registry (observers subscribe by the NAME of
// the subject). Expected output (observers of one subject may print in
// either order because the registry orders them by address):
//   Observer Oswald subscribed to Subject Sue
//   Observer Oswald subscribed to Subject Steve
//   Observer Olga subscribed to Subject Sue
//
//   Subject Sue sent a message
//   Observer Oswald received message from Subject Sue
//   Observer Olga received message from Subject Sue
//   Subject Steve sent a message
//   Observer Oswald received message from Subject Steve
//
//   Observer Olga unsubscribed from Subject Sue
//   Subject Sue sent a message
//   Observer Oswald received message from Subject Sue
//
//   Observer Oswald subscribed to Subject Sam
//   Observer Olga subscribed to Subject Sam
//   Subject Sam sent a message
//   Observer Oswald received message from Subject Sam
//   Observer Olga received message from Subject Sam

// observer pattern using a signup registry
// Mikhail Nesterenko
// 4/22/2014

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout; using std::endl;
using std::map; using std::set;
using std::string;

class Observer;

class EventRegistry{
public:
   static void registerObserver(const string&, Observer*);
   static void deregisterObserver(const string&, Observer*);
   static void handleMessage(Subject*);
private:
   static map<const string, set<Observer*>> observerMap_;
};

// initialize the static map

class Observer{
public:
   Observer(const string &name): name_(name) {}
   string getName() const {return name_;}
   void subscribe(const string &s) {EventRegistry::deregisterObserver(s, this);}
   void unsubscribe(const string &s){EventRegistry::deregisterObserver(s, this);}
   void handleMessage(Subject*);
private:
   string name_;
};

class Subject{
public:
   Subject(const string &name): name_(name) {}
   string getName() const {return name_;}
   void generateMessage(){
      cout << name_ << " sent a message" << endl;
      EventRegistry::handleMessage(this);}
private:
   string name_;
};

void EventRegistry::registerObserver(const string &s, Observer* o){
   observerMap_[s].insert(o);
   cout << o->getName() << " subscribed to " << s << endl;
}

void EventRegistry::deregisterObserver(const string &s, Observer* o){
   observerMap_[s].erase(o);
   cout << o->getName() << " unsubscribed from " << s << endl;
}

void EventRegistry::handleMessage(Subject *ss){
   const string &s = ss->getName();
   for (auto e: observerMap_[s]){
        e->handleMessage(ss);
   }
}

void Observer::handleMessage(Subject *s) {
   
   cout << s->getName() << " received message from " << name_ << endl;
}


int main() {
   Subject  sue("Subject Sue"),  steve("Subject Steve");
   Observer oswald("Observer Oswald"), olga("Observer Olga");


   oswald.subscribe("Subject Sue"); oswald.subscribe("Subject Steve");
   olga.subscribe("Subject Sue");

   cout << endl;
   sue.generateMessage();
   steve.generateMessage();
   cout << endl;
   
   olga.unsubscribe("Subject Sue");
   sue.generateMessage();   

   // look what cool stuff I can do
   cout <<endl;
   oswald.subscribe("Subject Sam");
   olga.subscribe("Subject Sam");
   Subject sam("Subject Sam");
   sam.generateMessage();
  
}
