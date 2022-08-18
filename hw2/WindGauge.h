#include <deque>

class WindGauge {
    public:
        WindGauge(int period  = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const; 
        int average() const;
        void dump();
    private:
        std::deque<int> speeds;
        int maxSpeed;
        int minSpeed;
        int sumSpeeds;
        int maxPeriod;
        int currentPeriod;
};