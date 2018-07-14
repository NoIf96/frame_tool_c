#include"tool_base.h"

#include<stdio.h>
#include<stdlib.h>

int main(void) {
	Table_border(0, 0, 30, 20, '*', '|' );
	Table_lines(0, 1, 28, '-', 4, 3);
	Table_tail(18, 1, 28, '-');

	Pos(15, 0);
	return 0;
}