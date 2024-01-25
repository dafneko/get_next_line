NAME = gnl.a
HEADERDIR = .
SRC = get_next_line.c get_next_line_utils.c
SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c 
CC = cc
CCFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
OBJ_BONUS=$(SRC_BONUS: .c=.o)
AR = ar rcs

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< -I $(HEADERDIR)

all: $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:
	all clean fclean re bonus so