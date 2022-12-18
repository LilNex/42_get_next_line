
NAME = gnl.a
HDRS = get_next_line_bonus.h
SOURCES = \
	get_next_line_bonus.c get_next_line_utils_bonus.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

%.o: %.c $(HDRS)
	$(CC) -c  $(CFLAGS) $<

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re%