PREFIX  = /usr
DATADIR = $(PREFIX)/share/$(TARGET)
CFLAGS  ?=  -Wall -Wno-deprecated-declarations -O3
ifeq '$(OS)' 'Windows_NT'
	LIBS = -laldmb -ldumb -lalleg	
else
	LIBS = -laldmb -ldumb `allegro-config --libs`
endif
DEFINES = -DDATADIR=\"$(DATADIR)/\"
OBJS    =  actor.o    edit.o  map.o       player.o    shooter.o unix.o \
           bullet.o   hisc.o  options.o   script.o    timer.o          \
           control.o  main.o  particle.o  scroller.o  token.o
TARGET  = lex4

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEFINES) -o $@ -c $<

install: $(TARGET)
	mkdir -p $(PREFIX)/bin
	mkdir -p $(DATADIR)
	install -p -m 755 $(TARGET) $(PREFIX)/bin
	install -p -m 644 ../data/*.dat $(DATADIR)

clean:
	rm -f $(OBJS) $(TARGET) *~


uninstall:

	rm -f $(PREFIX)/bin/$(TARGET)
	rm -rf $(DATADIR)


