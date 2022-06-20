#include "libft.h"
#include "ft_printf.h"

static int	ft_putptr(unsigned long int n, const char *ptr)
{
	int		len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putptr(n / 16, ptr);
	}
	len += ft_printchar(ptr[n % 16]);
	return (len);
}

int	ft_printptr(unsigned long int n, const char *ptr)
{
	int	len;

	if (!n)
		return (write(1, "(nil)", 5));
	len = 0;
	len += ft_printstr("0x");
	len += ft_putptr(n, ptr);
	return (len);
}
