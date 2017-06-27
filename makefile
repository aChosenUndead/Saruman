subsystem:
	cd Jokenpo && $(MAKE)
	cd Generator && $(MAKE)
	cd Grimoire && $(MAKE)
	@echo "\nSarumanJokenpo full compiled!\n"
clean:
	cd Jokenpo && $(MAKE) clean
	cd Generator && $(MAKE) clean
	cd Grimoire && $(MAKE) clean