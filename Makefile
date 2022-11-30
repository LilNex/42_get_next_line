
NAME = get_next_line.a
BNAME = get_next_line_bonus.a
HDRS = get_next_line.h
BHDRS = get_next_line_bonus.h
SOURCES = \
	get_next_line.c get_next_line_utils.c \

BSOURCES = \
	get_next_line_bonus.c get_next_line_utils_bonus.c \

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

bonus:$(BOBJECTS)
	$(AR) -r $(BNAME) $?

%_bonus.o: %_bonus.c $(BHDRS)
	$(CC) -c  $(CFLAGS) $<

%.o: %.c $(HDRS)
	$(CC) -c  $(CFLAGS) $<

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME) $(BNAME)
 
re: fclean all bonus

.PHONY: all bonus clean fclean re%