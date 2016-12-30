/*
Copyright (C) 2015 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#include "console.h"
#include "memory.h"
#include "process.h"
#include "interrupt.h"
#include "keyboard.h"
#include "mouse.h"
#include "clock.h"
#include "ata.h"
#include "cdromfs.h"
#include "string.h"
#include "graphics.h"
#include "ascii.h"
#include "syscall.h"
#include "rtc.h"
#include "kernelcore.h"
#include "kmalloc.h"
#include "memorylayout.h"


/*
This is the C initialization point of the kernel.
By the time we reach this point, we are in protected mode,
with interrupts disabled, a valid C stack, but no malloc heap.
Now we initialize each subsystem in the proper order:
*/

int kernel_main()
{
	struct graphics *g = graphics_create_root();

	console_init(g);

	console_printf("video: %d x %d\n",video_xres,video_yres,video_xbytes);
	console_printf("kernel: %d bytes\n",kernel_size);

	memory_init();
	kmalloc_init((char*)KMALLOC_START,KMALLOC_LENGTH);
	interrupt_init();
	rtc_init();
	clock_init();
	mouse_init();
	//keyboard_init();
	process_init();
	ata_init();

	


	// struct cdrom_volume *v = cdrom_volume_open(1);
	// if(v) {
	// 	struct cdrom_dirent *d = cdrom_volume_root(v);
	// 	if(d) {
	// 		cdrom_dirent_readdir(d,0,1);
	// 		cdrom_dirent_close(d);
	// 	} else {
	// 		printf("couldn't access root dir!\n");
	// 	}
	// 	cdrom_volume_close(v);
	// } else {
	// 	printf("couldn't mount filesystem!\n");
	// }
	console_reset();
	console_printf("\nMAGS-OS READY:\n\n");
  console_printf("Type help for instructions or type hello for a special message\n");


	string ch = (string) kmalloc(200);
	string string1;

	 do {
		console_printf("\n");
		console_printf("\nMAGS-OS> ");
		//ch = '\0';

		ch=readStr();
		
		for (int i=0; i<20; i++) 
			string1[i] = '\0';

		for (int i=0; i<strlen(ch)-1; i++) {
			string1[i] = ch[i];
	
		}


		if((strcmp(string1, "how long has it been") == 1)) {
			clock_t clock = clock_read();
			string time = int_to_string(clock.seconds);
			console_printf(time);
			console_printf("\n");

		} 

		else if(strcmp(string1, "time") == 1) {
			string real_time = rtc_fetch_time();
			console_printf(real_time);
			console_printf("\n");
		}

		else if(strcmp(string1, "date") == 1) {
			string real_date = rtc_fetch_date();
			console_printf(real_date );
			console_printf("\n");
		}

		else if ((strcmp(string1, "hello") == 1)) {
			console_printf("Welcome to MAGS-OS! Hope you find this interesting!\n");
		}

		else if ((strcmp(string1, "help") == 1)) {
			console_printf("\nCommands available:\n");
			console_printf("\nhello\ndate\ntime\nhow long has it been\nclear\n");
		}
		else if ((strcmp(string1, "clear") == 1)) {
			console_reset();
		} 

		else {
			console_printf("Sorry, I didn't quite get that\n");

		}

	} while (!strcmp(ch, "exit"));


	return 0;
}
