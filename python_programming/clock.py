import time # in pp the data is seperate from the functions that manipulate the data and in oop, the two things exist together in a class
#class contains the data and the algorithms that maninpulate that data
class Clock: # will be run in conjuction with other programmes, considered a template that you put data
    def __init__ (self, hours, mins, secs):
        self.hours = hours # class has control over the data - invalid inputs
        self.mins = mins # double underline method reserved function constructor creates a new instance of a clock
        self.secs = secs
        self.validate()

    def validate(self):
        if (self.hours > 12 or self.mins > 60 or self.secs >60):
            self.hours = 0
            self.mins = 0
            self.secs = 0

    def tick(self):
        self.secs += 1

        if(self.secs > 59):
           self.mins += 1
           self.secs = 0

        if(self.mins > 59):
           self.hours += 1
           self.mins = 0

        if(self.hours > 12):
           self.hours += 1
           self.mins = 0
           self.secs = 0

    def __repr__(self): # string based output
        return f"{self.hours} : {self.mins} : {self.secs}" # self means hours
        
        
if __name__ == '__main__':
    c = Clock(10,20,50)
    c2 = Clock(11,23,50)
    


    while (True): # only if this is the programme that I want to run 
        c.tick()
        print(f"Clock 1 {c}")
        print(f"Clock 2 {c2}")
        time.sleep(1) # different data but governs in the same algorithm 
        # difference between a class and an instance of a class

    