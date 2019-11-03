#ifndef SANA_EDGE
#define SANA_EDGE

template<typename T>
class Edge {
public:
    Edge(unsigned int source, unsigned int target, T value): 
        source(source), target(target), value(value) {};
    const unsigned int getSource() const {
        return source;
    }
    const unsigned int getTarget() const {
        return target;
    }
    const T getValue() const {
        return value;
    }

private:
    unsigned int source;
    unsigned int target;
    T value;
};
#endif
