LIBDIR := libs
OBJDIR := objs
EXEDIR := bin

EXE1 := $(EXEDIR)/out_s
EXE2 := $(EXEDIR)/out_d
OBJS1 := $(addprefix $(OBJDIR)/,matrixmath_add.o matrixmath_subtract.o matrixmath_multiply.o matrixmath_scale.o)
OBJS2 := $(addprefix $(OBJDIR)/,matrixmath_add_d.o matrixmath_subtract_d.o matrixmath_multiply_d.o matrixmath_scale_d.o)


vpath %.c src
vpath %.h include

all: run-so
run-a: build-a
	@echo "run static_s executable file in bin folder..."
build-a: $(EXE1)
$(EXE1): objs/image.o libs/libmatrixmath.a | $(EXEDIR)
	gcc -o $@ -I include $< -L libs -lmatrixmath
$(OBJDIR)/image.o: image.c matrixmath.h | $(OBJDIR)
	gcc -o $@ -c -I include $<
$(OBJDIR)/matrixmath_add.o: matrixmath_add.c matrixmath.h | $(OBJDIR)
	gcc -o $@ -c -I include $<
$(OBJDIR)/matrixmath_subtract.o: matrixmath_subtract.c matrixmath.h | $(OBJDIR)
	gcc -o $@ -c -I include $<
$(OBJDIR)/matrixmath_multiply.o: matrixmath_multiply.c matrixmath.h | $(OBJDIR)
	gcc -o $@ -c -I include $<
$(OBJDIR)/matrixmath_scale.o: matrixmath_scale.c matrixmath.h | $(OBJDIR)
	gcc -o $@ -c -I include $<

	

lib-a: libs/libmatrixmath.a
$(LIBDIR)/libmatrixmath.a: $(OBJS1) | $(LIBDIR)
	ar rcs $@ $^

tests: build-a build-so
	@echo "For the given input.ppm file in inputs folder, it generates all transformations(grey, invert and high contrast) in outputs folder and make sure there's only a single input file named input.ppm in inputs folder....."
run-so: build-so
	@echo "To generate all transformations for a new image make sure to place a input.ppm file in inputs folder and remove the previous one.."
	@echo "run dynamic_d executable file in bin folder..."
build-so: $(EXE2)
	@echo "take path of libs and run command $$export LD_LIBRARY_PATH=./libs:$-'dollarsign'LD_LIBRARY_PATH"
	@echo "now go to bin folder and run out_d executable file"
$(EXE2): image.c libs/libmatrixmath_d.so | $(EXEDIR)
	gcc -o $@ -I include $< -L libs -lmatrixmath_d
$(OBJDIR)/matrixmath_add_d.o: matrixmath_add.c matrixmath.h | $(OBJDIR)
	gcc -fPIC -c -I include $< -o $@
$(OBJDIR)/matrixmath_subtract_d.o: matrixmath_subtract.c matrixmath.h | $(OBJDIR)
	gcc -fPIC -c -I include $< -o $@
$(OBJDIR)/matrixmath_multiply_d.o: matrixmath_multiply.c matrixmath.h | $(OBJDIR)
	gcc -fPIC -c -I include $< -o $@
$(OBJDIR)/matrixmath_scale_d.o: matrixmath_scale.c matrixmath.h | $(OBJDIR)
	gcc -fPIC -c -I include $< -o $@

lib-so: libs/libmatrixmath_d.so
$(LIBDIR)/libmatrixmath_d.so: $(OBJS2) | $(LIBDIR)
	gcc -shared -o $@ $^

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(EXEDIR):
	mkdir -p $(EXEDIR)
$(LIBDIR):
	mkdir -p $(LIBDIR)
.PHONY: clean
clean:
	rm -rf $(EXEDIR) $(OBJDIR) $(LIBDIR)
