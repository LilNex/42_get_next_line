for (( ; ; ))
do
	clear	
	gcc get_next_line.c -Wall -Werror -Wextra -D BUFFER_SIZE=42
	sleep 1.3
	clear
	./a.out 
	sleep 2
done

