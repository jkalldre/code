function call()
{
  if (vali())
  {
    document.getElementById('err').innerHTML = "";
  var startCity = document.getElementsByTagName('input')[0].value;
  var startState = document.getElementsByTagName('input')[1].value;
  var endCity = document.getElementsByTagName('input')[2].value;
  var endState = document.getElementsByTagName('input')[3].value;
//  window.location.href += "?startCity=" + startCity + "&startState=" + startState +
//  "&endCity=" + endCity + "&endState=" + endState;
  var url = "http://localhost/cgi-bin/ercanbracks/mileage/mileageAjaxXML" +
  "?startCity=" + startCity + "&startState=" + startState +
  "&endCity=" + endCity + "&endState=" + endState;
  var request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if (request.readyState == 4)
    {
      if (request.status == 200)
      {
         var xml = request.responseXML;
         var str = "Trip info:\nStart: " + xml.getElementsByTagName('startcity')[0].childNodes[0].nodeValue
         + ", " + xml.getElementsByTagName('startstate')[0].childNodes[0].nodeValue + "\nDestination: "
         + xml.getElementsByTagName('endcity')[0].childNodes[0].nodeValue + ", " + xml.getElementsByTagName('endstate')[0].childNodes[0].nodeValue
         + "\nMiles: " + xml.getElementsByTagName('miles')[0].childNodes[0].nodeValue + "\nMode of Trasport: " + xml.getElementsByTagName('tmode')[0].childNodes[0].nodeValue;
         document.getElementById('inp').innerHTML = str;//xml.getElementsByTagName('startcity')[0].childNodes[0].nodeValue;
      }
    }
  }
  request.open("GET", url, true);
  request.send();
  }
}

function vali()
{
  if (document.getElementById('sCity').value != ""
   && document.getElementById('sState').value != ""
   && document.getElementById('eCity').value != ""
   && document.getElementById('eState').value != "")
   {
     return true;
   }
   else {
     document.getElementById('err').innerHTML = "*Please Fill Out All Fields*";
     return false;
   }
}
