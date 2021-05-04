#include <iostream>
using namespace std;

// Multiple inheritance
// Problem: You have ambiguos methods and to resolve them you need by knowing the implementation details of the derived class

class MusicalInstrument {
public:
    virtual void play() { cout << "Playing instrument ..." << endl; }
    virtual void reset() { cout << "Resetting instrument ..." << endl; }
    virtual ~MusicalInstrument() {}
};

class Machine {
public:
    virtual void start() { cout << "Starting machine ..." << endl; }
    virtual void reset() { cout << "Resetting machine ..." << endl; }
    virtual ~Machine() {}
};

class Synthesizer : public MusicalInstrument, public Machine {
public:
    virtual ~Synthesizer() {}
};

int main() {

    Synthesizer *pSynth = new Synthesizer();

    pSynth->play();
    pSynth->start();

    pSynth->Machine::reset();

    delete pSynth;
    return 0;
}