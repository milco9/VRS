# Náplň cvičenia
- zoznámenie sa s prerušeniami - NVIC
- konfigurácia externých prerušení od GPIO s EXTI

# Prerušenia
- "prerušenie" preruší vykonávania hlavnej slučky programu a vykoná sa fukcia, obsluha prerušenia, po ktorej vykonaní bude pokračovať beh hlavnej slučky programu

- ak nastane viacero prerušení, začne sa vykonávať prerušenie s najvyššou prioritou

- v MCU s ARM architektúrou má prerušenia na starosť NVIC

### NVIC - Nested Vector Interrupt Controller (stm32F303K8)
- 16 programovateľných úrovní priority prerušenia (4 bity)
<p align="center">
    <img src="https://community.arm.com/cfs-file/__key/communityserver-blogs-components-weblogfiles/00-00-00-21-42/4212.figure_5F00_2_5F00_nested_5F00_interrupt.jpg" width="600">
</p>

- 76 maskovateľných vektorov prerušení
<p align="center">
    <img src="https://community.arm.com/cfs-file/__key/communityserver-blogs-components-weblogfiles/00-00-00-21-42/6378.figure_5F00_3_5F00_nvic.jpg" width="400">
</p>

- tabulka vektorov prerušení a ich obsluha je definovaná v súbore "startup_stm32f303x8.s"

# Zadanie
- Podľa ukážkového programu z vetvy "master" nakonfigurujte MCU tak, aby tlačidlo pripojené ku vstupnému GPIO pinu bolo zdrojom externého prerušenia a LED pripojená ku výstupnému GPIO pinu zmenila svoj stav po každom stlačení tlačidla.

### Úlohy
- Stiahnúť/naklonovať vetvu "zadanie_cv4", ktorá predstavuje šablónu projektu, do ktorej je nutné vypracovať nasledujúce úlohy.
- Pre svoje zadanie si vtvoriť vlastný github repozitár, kam sa nahraje stiahnutá šablóná.

- V súbore "Src/main.c" implementovať konfiguráciu GPIO periférii. GPIOB-4 je vyhradené pre tlačidlo a GPIOA-4 je vyhradené pre LED.
- V súbore "Src/main.c" implementovať konfiguráciu EXTI pre vstupný pin, ku ktorému je pripojené tlačidlo.
- V súbore "Src/main.c" implementovať funkciu "checkButtonState", ktorej deklarácia sa nachádza v "Inc/assignment.h".
- V súbore "Inc/assignment.h" upraviť hodnoty makier, ktoré slúžia ako vstupné argumenty do funkcie "checkButtonState", podľa vlastnej potreby.

