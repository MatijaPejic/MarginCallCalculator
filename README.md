# MarginCallCalculator

**Kratak Opis:**</br>
- Sistem za verzionisanje: Git </br>
- Alat za prevodjenje: CMake </br>
- Jos neki korisceni alati: ClangFormat, ClangTidy, GDB </br>
- Issues sekcija je koriscena za pracenje taskova na "prici" gde se implemenira algoritam za racunanje margin call-a, (skoro)sve implementacije su isle kroz zasebne /feature grane koje su pushovane na repo i mergovane na mainline i mogu se videti u sekciji branches, dok se pull requestovi mogu videti u svojoj sekciji </br>
- Par inicijalnih komitova je islo direktno na mainline sto nije idealno </br>
- Grane i taskovi su obelezene odgovarajucim labelama (enhancement, documentation ili bug) </br>
- Za resavanje bagova koriscen je GDB kroz okruzenje VSC, za reseni bug mogu se videti screenshot-ovi na odgovarajucem pull requestu koji je obelezen labelom bug
(idealno bi bilo da je postojala posebna bugfix/ grana za bug ali se on desio tokom implementacije algoritma pa je zato na toj grani) </br>
- ClangTidy i Format imaju zasebne grane pa se njihovi rezultati mogu odvojeno videti (Tidy nam je otklonio potencionalne memory leak-ove)






**Sta je Margin a sta Margin call i njihova svrha:** </br>
In the financial world clients can do something called invest on margin. Investing on margin allows clients to invest more money into companies that they think will do well in the future. When clients want to invest they can borrow money from a broker and then invest both their own money and the brokers money thus having more profit if the stock value of the company increases. In order to acquire a margin position the client must invest 50% of the total money in the position. For example, if the client invests 50 000$ and borrows 50 000$ he is eligable for a margin position because his investment of 50 000$ is 50% of the total money in the position wich is 100 000$.
If the stock value of the company increases by, for example, 25% the 100 000$ will increase to 125 000$, once the broker is paid his 50 000$ (we will assume that there is no interest, but usually there is) we are left with 75 000$ wich is a profit of 25 000$ on our initial investement, wich is a higher profit then if we never borrowed the money thus the insetive to acquire margin positions. On the other hand the stock value of the company can go down. Lets assume that the stocks dropped by 25% and that our 100 000$ turned into 75 000$. In this case the broker's have something called the margin maintenance treshold. The margin maintenance treshold is the minimal amount of money that the broker requires us to have on our account, and it is a percentage of the current amount of money that belongs to the client. In our example lets say that the treshold is 35%. In that case out of our 75 000$, 25 000$ is ours once the broker is paid off. This 25 000$ is 33.33% of the total value wich is 75 000$
thus we are under the treshold. In this case a Margin Call is made. Margin calls calculate the amount of money that the client needs to deposit to their account in order to meet the margin maintenance treshold. If the client cannot make the deposit the broker can sell the shares in order to make his money back, if the broker cannot make all his money back certain legal actions can be taken.
