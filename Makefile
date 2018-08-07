CC=UV4
OPTS=-j0
PROJ_FILE=K64F_ethernet.uvprojx
OUTPUT_FILE=output.txt

.PHONY: build
build:
	-$(CC) -b -b $(PROJ_FILE) -o $(OUTPUT_FILE) $(OPTS)
	@cat output.txt
	@rm output.txt

.PHONY: clean
clean:
	$(CC) -c -c $(PROJ_FILE) -o $(OUTPUT_FILE) $(OPTS)
	@cat output.txt
	@rm output.txt

.PHONY: program
program:
	-$(CC) -f -f $(PROJ_FILE) -o $(OUTPUT_FILE) $(OPTS)
	@cat output.txt
	@rm output.txt
