SELECT Person.firstname, Person.lastname, Address.city, Address.state FROM Person LEFT JOIN Address on Person.personId = Address.personId
