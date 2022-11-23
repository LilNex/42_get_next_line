
NAME = libftprintf.a
HDRS = ft_printf.h
SOURCES = \
	ft_printf.c ft_utils.c ft_utils2.c \

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