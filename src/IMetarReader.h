#ifndef IMETARREADER_H
#define IMETARREADER_H

namespace altran {
namespace suncloud {

class IMetarReader {
public:
    virtual ~IMetarWriter() {}

    virtual void read(const std::chrono::time_point<std::chrono::system_clock>& requestDate) = 0;
};

typedef std::shared_ptr<IMetarReader> PIMetarReader;

}
}

#endif // IMETARREADER_H

