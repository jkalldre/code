function firstFocus(name)
{
  document.getElementById(name).focus();
}

function getInfo()
{
  var country = document.getElementById("countries").value;
  getDoc("http://localhost/~ercanbracks/usa.txt", 0);

  if (country == "0")
  getDoc("http://localhost/~ercanbracks/usa.txt", 0);

  else if (country == "1")
  getDoc("http://localhost/~ercanbracks/mexico.txt", 0);

  else if (country == "2")
  getDoc("http://localhost/~ercanbracks/canada.txt", 0);

  else if (country == 3)
  getDoc("http://localhost/~ercanbracks/russia.txt", 0);
}


function getDoc(url, num)
{
  var request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if (request.readyState == 4)
    {
      if (request.status == 200)
      {
        change(request);
      }
    }
  }
  request.open("GET", url, true);
  request.send();
}

function getDoc1(url, num)
{
  var request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if (request.readyState == 4)
    {
      if (request.status == 200)
      {
        json(request);
      }
    }
  }
  request.open("GET", url, true);
  request.send();


}
function change(request)
{
  document.getElementById('info').innerHTML = request.responseText;
}

function json(request)
{
   var text = request.responseText;
   var obj = JSON.parse(text);
   var insert = "<table><tr><th>First</th><th>Last</th><th>Address</th><th>Major</th><th>GPA</th></tr>";
   var i;
   for (i = 0; i < obj.students.length; i++)
   {
     insert = insert + "<tr><td>" + obj.students[i].first + "</td><td>"
    + obj.students[i].last + "</td><td>"   +  obj.students[i].address.city + ", "
    + obj.students[i].address.state + ": " + obj.students[i].address.zip + "</td><td>"
    + obj.students[i].major + "</td><td>"  +  obj.students[i].gpa + "</td></tr>";
   }
   insert = insert + "</table>";
  document.getElementById('jsonInsert').innerHTML = insert;
}
