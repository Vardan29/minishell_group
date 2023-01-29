NAME			=	libft.a
CFLAGS			=	-Wall -Wextra -Werror
ALL_SOURCES		=	$(wildcard *.c)
BONUS_SOURCES 	=	$(wildcard ft_lst*.c)
SOURCES			=	$(filter-out $(BONUS_SOURCES), $(ALL_SOURCES))
OBJECTS			=	$(patsubst %.c, %.o, $(SOURCES))
BONUS_OBJECTS	=	$(patsubst %.c, %.o, $(BONUS_SOURCES))
AR				=	ar rcs
RM				=	rm -f

%.o:%.c
	$(CC) $(CLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

bonus: $(NAME) $(BONUS_OBJECTS)
	$(AR) $(NAME) $(BONUS_OBJECTS)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all bonus clean fclean re
