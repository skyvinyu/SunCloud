#ifndef FLIGHTROUTESCILABWRITER_H
#define FLIGHTROUTESCILABWRITER_H

#include "IFlightRouteWriter.h"


namespace altran {
namespace suncloud {


class FlightRouteScilabWriter : public IFlightRouteWriter
{
public:
    FlightRouteScilabWriter();
    ~FlightRouteScilabWriter();

    virtual void write(std::ostream& os);


    template <typename Point>
    class PointWriter {
    public :
        PointWriter(std::ostream& os)  :
            m_os(os){}

        void operator()(Point& p) {
            m_os << boost::geometry::get<0>(p) << " "
                 << boost::geometry::get<1>(p) << " "
                 << boost::geometry::get<2>(p) << std::endl;
        }

    private :
        std::ostream& m_os;

    };

//    /**
//     * @brief flushPoint  Flush point to stream
//     * @param p   point type
//     * @param os    Output stream
//     */
//    template <typename Point>
//    void flushPoint(Point const& p, std::ostream& os) {
//        os << boost::geometry::get<0>(p) << " "
//           << boost::geometry::get<1>(p) << " "
//           << boost::geometry::get<2>(p) << std::endl;
//    }

    void flushStartTime(std::ostream& os);
    void flushPoints(std::ostream& os) ;

private:

    std::tm getLocalTm();
    int getStartDaysOfYear();

};

}
}

#endif // FLIGHTROUTESCILABWRITER_H
