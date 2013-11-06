//
//  main.cpp
//  scanfile
//
//  Created by taowei on 13-11-6.
//  Copyright (c) 2013年 taowei. All rights reserved.
//

#include <iostream>
//扫描目录下的文件
char get_file_name()
{
	system("find /tmp/ -type d >file_path_name.txt");
	system("find /tmp/ -type d | wc -l >file_path_num.txt");
	system("find /tmp/ -name '*' | wc -l >file_num.txt");

	FILE *fp_cont, *fp_num;
	file_msg file_mesgs;

	fp_num = fopen("file_num.txt", "r");
	fscanf(fp_num, "%d", &file_mesgs.nums);
	fclose(fp_num);

	fp_cont = fopen("file_path_num.txt", "r");
	fscanf(fp_cont, "%", &file_mesgs.cont);
	fclose(fp_cont);

	printf("%d\n%d\n", file_mesgs.nums, file_mesgs.cont);

	FILE *fp_path;
	fp_path = fopen("file_path_name.txt", "r");
	file_mesg files_mesgs[file_mesgs.cont];

	for (int i = 1; i <= file_mesgs.cont; i++) {
		fscanf(fp_path, "%s", files_mesgs[i].paths);
		printf("%s\n",file_mesgs[i].paths);
	}
}

int mian()
{
	get_file_name();
	return 0;
}
