for (( ; ; ))
do
	clear	
	gcc get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -D BUFFER_SIZE=10
	sleep 0.3
	clear
	timeout 2s ./a.out 
	sleep 3
	sleep 
done

