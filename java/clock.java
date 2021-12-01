public class Clock extends Object { //stronger methods of private/public than Python

    private int hours;
    private int mins;
    private int secs;

    public Clock (int h, int m, int s){
        hours = h;
        mins = m;
        secs = s;
        validate();
    }

    private void validate (){ //private method, can't access it outside the methods]
        if (hours > 12 || mins > 60 || secs > 60){
            hours = 0;
            mins = 0;
            secs = 0;
        }
    }

    public void tick (){
        secs += 1;

        if (secs > 59){
            mins += 1;
            secs = 0;
        }

        if (mins > 59){
            mins += 1;
            secs =  0;
        }

         if (hours > 12){
            mins += 1;
            secs =  0;
        }
    }

    public String toString() {
        return hours+":" +mins+ ":"+secs;
    }

    public static void main(String[] args) throws InterruptedException {
        Clock c = new Clock(10,20,50);
        c.validate();

        while(true){
            c.tick();
            System.out.printIn(c);
            Thread.sleep(1000) ;
        }
    }
}