for (( ; ; ))
do
	clear	
	gcc get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -D BUFFER_SIZE=10
	sleep 1.3
	clear
	./a.out 
	sleep 2
done

