
extern "C" 
{
void D_DoomMain (void);
}

extern unsigned long _sbss_sdram;     /* start address for the .bss section. defined
                                   in linker script */
extern unsigned long _ebss_sdram;     /* end address for the .bss section. defined in
                                   linker script */

void doomBegin()
{
  volatile unsigned long *pulDest;

  for(pulDest = &_sbss_sdram; pulDest < &_ebss_sdram; )
  {
    *(pulDest++) = 0;
  }

  D_DoomMain();
}

