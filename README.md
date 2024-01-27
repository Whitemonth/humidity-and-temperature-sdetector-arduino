# humidity-and-temperature-detector-arduino

=======

Arduino+NodeJS Climate Exchange.

---

Arduino collects data from the temperature and humidity sensor, formats the data into json format and sends it via the COM port. NodeJS listens to the COM port, collects data and parses JSON into a regular object. Then, through a simple http server, the information is provided to the UI in localhost.

Data refreshing counter is 5s. "delay(5000)";

---

Tested on arduino nano.

> > > > > > > master
