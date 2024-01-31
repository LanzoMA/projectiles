class Arrow {
public:
    Arrow();        
    ~Arrow();        

    size_t getLength();
    void setLength(size_t newLength);

    double getDirection();
    void setDirection(double newDirection);

private:
    size_t length;
    double direction;
}
