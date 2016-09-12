#pragma once
#include "Atomics.h"

using TIME = U64;

class Platform
{
/////////////////
// CLOCK/TIMER //
/////////////////

  // think about how to add a class  that is a timer, aka calls a function after timer completes
  // that timer class will be used to call functions
  // Timer: a device (as a clock) that indicates by a sound the end of an
  //  interval of time or *that starts or stops a device at predetermined times*
  //  A timer makes an anouncement(calls a function) after a specified durations
  //  (should the time make the direct function call, or send a message, or do a Notification
  //  Notification
  class Timer
  {
    void Start()=0;
    void Stop()=0;

    void Pause()=0;
    void Resume()=0;
  }
  // Clock: a device other than a watch for indicating or measuring time
  //    commonly by means of hands moving on a dial; broadly
  //    :  any periodic system by which time is measured
  // A clock measure time elapsed
  class Clock
  {
    void Start()=0;
    void Stop()=0;

    void Pause()=0;
    void Resume()=0;

  private:
    Clock(){}
    ~Clock(){}
  }

  // milliseconds: the time interval for which execution is to be suspended
  virtual void Sleep(U64 milliseconds) = 0;

  // handle: a handle to the output buffer. It should be to a console
  // characterAttributes: the character attributes
  S32 SetConsoleTextAttribute(void* handle, U16 characterAttributes) = 0;

  // retrieves a handle to the specified standard device
  void* GetStdHandle(U64 stdHandle);

// Input Output
  void WaitForKeyboardInput(void);
  S32 _kbhit( void )
/////////////////////
// WINDOW / SCREEN //
////////////////////
  class Window
  {
    void Start()=0;
    void Stop()=0;

    void Pause()=0;
    void Resume()=0;
    // not including Pause(TIME ms); to keep things simple and more debuggable
  }

///////////////
// THREADING //
///////////////
  class Thread
  {
    void Start()=0;
    void Stop()=0;

    void Suspend()=0;
    void Resume()=0;
  }
};
// and it all started with wondering if my Timer class should make a notification
// or if it should make a call to a function. I think I will have the timer 
// give a Notification because that is what times do in the real world, they say 
// something. They alert
// Alert:
//    :watcehful and prompt to meet danger or emergency
//    :quick
//    Alert will not became a class because it is too specific of a word.
//    It is too pressing and, it has many meanings. They are related, but it
//    makes for a poor definition
  // All definitions taken from merrium webster
  // Notification:
  //    :the act or an instance of notifying
  //    :a written or printed matter that gives information about something that is going to happen
  // Notice:
  //    :Information that tells you or warns you about something that is going to happen
  //    :A statement telling someone that an agreement, job, etc. will end soon
  //    :Attention that people give to someone or something
  // Notify:
  //    :to give notice of or report the occurence of
  //    :to give formal notice to
  // Message:
  //    :a piece of information that is sent or given to someone

  // Event:
  //    :something (especially something important or notable) that happens
  //    :a planned occasion or activity(such as a social gathering)
  //Observe:
  //    :to watch and sometimes also listen to
  //    :to take notice
  //Observer:
  //    :a person who sees and notices someone or something
  //    :a person who is present at something(such as a meeting) in order to watch and listen to what happens
  
// How is a Message Different than a Notification
//    -A message can be more verbose.
//    -A notification can be very small (like a sound)
//    -A message may be read now, later or never
//    -A notification is always heard immediately (like a timer notification)
//    
// Why is there a need for both?e
//    -Performance impact of the two is not equivalent
//    -They have different behaviors.
//    -There are times when a message is not timely
//
// Dose a notification alert an observer?
//    -No, a notification is not as demanding of action. It seems that we may have use
//    for Alert as well.
//
// What is interesting is looking at googles https://support.google.com/adxbuyer/answer/2655340?hl=en
//    -Uses Alerts, Anouncements, and Notifications Which inherit from Message.
//    -Alerts:
//        :These are the most important kind of action. They can be about a potential problem to fix
//        They may demand action
//        :Is seems that an alert is paired with a Warning
//    -It seems that what we have are messages with 4 levels of priority
//    -At the base level is a Message, then comes Notification, Then Anouncements, the Alert.
//    -Alert is the only one that comes with a guarantee that it will be noticed.
//    -this brings me back to what I originally avoided. A Timer Alerts.
//


// How to gaurantee a shared interface

class Warning
{
  Alert(const Observer&);
}
class Announcement
{
  Announce(const Observer&);

}
class Notification
{
  void Notify(const Observer&);

}
class Message
{
  void Deliver(const Observer&);
}
// but none of these demands action... what demands action? It is the final piece that is missing
// Command
//    :to give (someone) an order : to tell (someone) to do something in a forceful and often official way
//    : to have authority and control over (a group of people, such as soldiers)
//    : to deserve or be able to get or receive something
// One qualm I have is wether a command is an anti-pattern when it comes to threading.
// Will it make threading more difficult? Does it break encapsulation?
// My reply is, the right tool for the job, but still consider these questions.
class Command
{
  void Order(const Observer&);

}

//
// Alert:
//    :warn(someone) of a danger, threat, or problem, typically with the intention of having it
//    avoided or dealt with
//    :an urgent notice
// Warning:
//    
//    -
  class Message 
  {

  }
  class Notification
  {
    Notify(const Observer&);

  }

  class Observer
  {
    void Observe();
    void CheckMessages();
    // when the observer sees a notification
    void OnNotice();

  }
// rejection pile
