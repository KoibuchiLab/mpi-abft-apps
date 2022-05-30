/*
	    Copyright (c) NEC Corporation 2017. All rights reserved.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#define debug_printf printf 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <mpi.h>
#include <sys/time.h>
#include "Lib_xbar/Xbar_SR.h"

int rank,root,size;

int main(int argc, char *argv[])
{
	unsigned int ii;
	unsigned int *input_data=NULL;
	unsigned int *output_data=NULL;
	unsigned int data_num = 0;;
	int send_rank, recv_rank;

	OPTWEB_MPI_Init(&argc, &argv);
	OPTWEB_MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size); // "size" is the number of processes

	/* main process */
	data_num=atoi(argv[1])/sizeof(int);
	send_rank=atoi(argv[2]);
	recv_rank=atoi(argv[3]);

	input_data = (int*)malloc(sizeof(int)*data_num);
	output_data = (int*)malloc(sizeof(int)*data_num);

	for(ii=0; ii<data_num; ii++)
		input_data[ii] =ii;

	MPI_Status pstatus;
 	if(rank==send_rank){
		printf("Start Send Size:%dByte rank:%d\n", atoi(argv[1]), rank);
		OPTWEB_MPI_Send(input_data, data_num, MPI_INT, recv_rank, 0, MPI_COMM_WORLD); 
		printf("End Send rank:%d\n", rank);
	}else if(rank==recv_rank){
		printf("Start Recv Size:%dByte rank:%d\n", atoi(argv[1]), rank);
		OPTWEB_MPI_Recv(output_data, data_num, MPI_INT, send_rank, 0, MPI_COMM_WORLD, &pstatus); 
		printf("End Recv rank:%d\n", rank);
	}
	/* close devices */
	OPTWEB_MPI_Finalize();
	if(input_data)
		free(input_data);
	if(output_data)
		free(output_data);
	return 0;
}
