
class Pixel:
    def __init__(self, *args) -> None:
        self.__rgb = bytearray(args)

    def __str__(self) -> str:
        return f'{self.red:02X}{self.green:02X}{self.blue:02X}'

    @property
    def red(self):
        return self.__rgb[0]

    @red.setter
    def red(self, value):
        self.__rgb[0] = value

    @property
    def green(self):
        return self.__rgb[1]

    @green.setter
    def green(self, value):
        self.__rgb[1] = value

    @property
    def blue(self):
        return self.__rgb[2]

    @blue.setter
    def blue(self, value):
        self.__rgb[2] = value

    def __lshift__(self, pixel):
        self.red = pixel.red
        self.green = pixel.green
        self.blue = pixel.blue