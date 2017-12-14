CREATE TABLE orders( id INT not null
, purchased_by int          not null
, item_name    VARCHAR(20)  not null
, date_bought  DATE         not null
, constraint orders_pk PRIMARY KEY (id)
, constraint orders_fk FOREIGN KEY (purchased_by) REFERENCES customer(id));

CREATE SEQUENCE seq2
START WITH 1
INCREMENT BY 1;

INSERT INTO orders
VALUES (seq2.nextval
, (SELECT id FROM customer WHERE name='Jake'
                           and   age='23')
, 'cookie'
, sysdate);

INSERT INTO orders
VALUES (seq2.nextval
, (SELECT id FROM customer WHERE name='Daniel'
                           and   age ='22')
, 'gluten-free cookie'
, sysdate);

INSERT INTO orders
VALUES (seq2.nextval
, (SELECT id FROM customer WHERE name='Jake'
                           and   age ='23')
, 'fig bar'
, '13-NOV-17');

INSERT INTO orders
VALUES (seq2.nextval
, (SELECT id FROM customer WHERE name='Colleen'
                                 and   age ='18')
, 'pizza'
, sysdate);

