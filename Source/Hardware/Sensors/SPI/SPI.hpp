#ifndef __MA3_HPP__
#define __MA3_HPP__
class SPI
{
    private:
      bool m_initialized;
      int m_file_descriptor;
      int m_channel_config;

    public:
        SPI();
        ~SPI();

        bool  init(int spi_channel);
        int   read(int spi_channel);
};
#endif//__MA3_HPP__
