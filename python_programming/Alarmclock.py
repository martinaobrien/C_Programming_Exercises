from clock import *

class AlarmClock (Clock):
    def __init__ (self, hours, mins, secs, aHour, aMin, aSec):
        super().__init__ (hours, mins, secs)
        self.aHour = aHour 
        self.aMin = aMin 
        self.aSec = aSec
        self.validate()

    def tick(self):
        if (self.hours == self.aHour and self.mins == self.aMin and self.secs == self.aSec):
            print ("Alarm, get up!!!!")

        super().tick() #can be said to be overwriting the superclass method
        #rule of thumb, if you are extending your method from the superclass then you should be calling it from the superclass

    def __repr__(self):
        return f"Alarm Clock:{super().__repr__()}"

if __name__ == '__main__':
    c = AlarmClock(10,20,50, 10,20,55)
    c2 = Clock(11,55,10)
    arr ={c,c2} 
    
    while (True): # only if this is the programme that I want to run 
        for clock in arr: # this idea is the beginnings of polymorphism, alarm clock and the clock are different things but we treated them the same and put them in an array together
            print(clock) # polymorphism ctd we can call the same methods on them
            clock.tick() # any call to the superclass can be substiuted to a call to the subclass, subclass shouldn't break the super class 
            time.sleep(1) # more advance topic in relation to oop 

# rper method when you are trying to print out a method it will look for the rper method, if the subclass doesn't have it, it will look to the super class and then  the higher levels
# if you don't have a rper method it goes to the default object