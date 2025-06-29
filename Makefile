gpioctl_mock: gpioctl_mock.c
	gcc -Wall -o gpioctl_mock gpioctl_mock.c

clean:
	rm -f gpioctl_mock
