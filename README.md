# ft_printf

questions pdf: <https://github.com/akaylee/42-holygraph>

## TODO

`man 3 printf / man 3 stdarg`

### Mandetory

The prototype of ft_printf should be int ft_printf(const char *, ...);

- You have to recode the libc’s printf function
- It must not do the buffer management like the real printf
- It will manage the following conversions: cspdiuxX%
- It will manage any combination of the following flags: ’-0.*’ and minimum field width with all conversions
- It will be compared with the real printf
- You must use the command ar to create your librairy, using the command libtool is forbidden.

```C
/*
 * int  ft_printf(const char *format, ...);
 *
 *
 *  %[$][flags][width][.precision][length modifier]conversion
 *
 *
 *
 *
 *      conversion  ==  c s p d i u x X %
 *      flags       ==  - 0 . *
 *
 *      CONVERSIONS
 * arg
 *      int             d i ->      signed decimal notation
 *      unsigned int    u x X       unsigned decimal, hexadecimal
 *      int             c           write char
 *      const char *    s           write string
 *      void *          p           hexadecimal (as if by %#x or %#lx)
 *
 *  BONUS
 *      conversion  ==  nfge
 *      flags       ==  l ll h hh
 *      all falgs   ==  #   +       (yes, one of them is a space)
 *
 */
```

### BONUS

If the Mandatory part is not perfect don’t even think about bonuses

- You don’t need to do all the bonuses
- Manage one or more of the following conversions: nfge
- Manage one or more of the following flags: l ll h hh
- Manage all the following flags: ’# +’ (yes, one of them is a space)
