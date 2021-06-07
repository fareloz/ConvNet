#pragma once

#include <vector>

namespace ConvNetLib {

    struct MapDims {
        uint64_t width;
        uint64_t height;
    };

    struct MapIndex {
        uint64_t w;
        uint64_t h;
    };

    class IConvMap {
    public:
        IConvMap() = default;
        IConvMap(const IConvMap&) = default;
        IConvMap(IConvMap&&) = default;
        IConvMap& operator=(const IConvMap&) = default;
        IConvMap& operator=(IConvMap&&) = default;
        virtual ~IConvMap() = 0;

        virtual uint64_t Size() const = 0;
        virtual uint64_t Width() const = 0;
        virtual uint64_t Height() const = 0;
        virtual MapDims Dims() const = 0;

        virtual double& operator[](MapIndex index) = 0;
        virtual double operator[](MapIndex index) const = 0;
    };

    class ConvMap : public IConvMap {
    public:
        ConvMap(MapDims dims);
        ConvMap(const ConvMap&) = default;
        ConvMap(ConvMap&&) = default;
        ConvMap& operator=(const ConvMap&) = default;
        ConvMap& operator=(ConvMap&&) = default;
        virtual ~ConvMap() = default;

        inline uint64_t Size() const override { return m_data.size(); }
        inline uint64_t Width() const override { return m_dims.width; }
        inline uint64_t Height() const override { return m_dims.height; }
        inline MapDims Dims() const override { return m_dims; };

        inline double& operator[](MapIndex index) override {
            return m_data[index.h * Width() + index.w];
        }
        inline double operator[](MapIndex index) const override {
            return m_data[index.h * Width() + index.w];
        }

    private:
        const MapDims m_dims;
        std::vector<double> m_data;
    };

}
