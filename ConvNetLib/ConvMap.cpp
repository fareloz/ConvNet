#include "ConvMap.h"

namespace ConvNetLib {

    ConvMap::ConvMap(MapDims dims)
        : m_dims(dims), m_data(dims.height* dims.width)
    {
    }

}
