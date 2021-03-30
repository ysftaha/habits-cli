drop table if exists habits;
drop table if exists Logs;

create table Habits (
    id  			integer not null primary key autoincrement,
		name  		nchar not null,
		sDate  		date not null,
		repeat  	int,
		frequency int,
		check((frequency is null and repeat>0) <> (repeat is null and frequency>0))
);

create table Logs (
	ldate date not null,
	hid  	integer not null,
	comp  integer not null,
	foreign key(hid) references Habits(id),
	primary key(hid, ldate)
);

insert into Habits (name, sDate, repeat) values("Exercise", "2021-01-01", 1);
insert into Logs (ldate, hid) values("2021-01-01", (select id from Habits where name = "Exercise"));
