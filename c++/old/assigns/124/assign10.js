function image(num)
{
  var pictures = ['rocket1.jpg', 'spaceship1.jpg', 'spaceship2.jpg',
  'spaceship3.jpg', 'spaceship4.jpg']
  document.getElementById('cPhoto').src = pictures[num];
}

function validate()
{
  if (validateContactInfo() &&
  validatePhone() &&
  validateCardType() &&
  validateCCN() &&
  validateExp())
  return true;
  else {
    return false;
  }
}

function validateCardType()
{
  if (document.getElementById('visa').checked ||
  document.getElementById('master').checked ||
  document.getElementById('express').checked)
  return true;
  else
  {
    document.getElementById('err').innerHTML = "*Please Select a Card Type.";
    document.getElementById('err').style.visibility = 'visible';
    return false;
  }
}

function validateContactInfo()
{
  if (document.getElementById('fName').value != ""
  && document.getElementById('lName').value != ""
  && document.getElementById('address').value != "")
  {
    return true;
  }
  else
  {
    document.getElementById('fName').focus();
    document.getElementById('err').innerHTML = "*Please fill out ALL contact information.";
    document.getElementById('err').style.visibility = 'visible';
    return false;
  }
}

function validatePhone()
{
  var num = document.getElementById('phone').value;
  var ok = num.search(/^\d{3}-\d{3}-\d{4}$/)
  if (ok == 0)
  return true;
  else
  {
    document.getElementById('phone').focus();
    document.getElementById('err').innerHTML = "*Please provide number in the ###-###-#### format.";
    document.getElementById('err').style.visibility = 'visible';
    return false;
  }
}

function validateCCN()
{
  var num = document.getElementById('ccn').value;
  var ok = num.search(/^\d{16}$/);
  if (ok == 0)
  return true;
  else
  {
    document.getElementById('ccn').focus();
    document.getElementById('err').innerHTML = "*Please enter complete Credit card number.";
    document.getElementById('err').style.visibility = 'visible';
    return false;
  }
}

function validateExp()
{
  var exp = document.getElementById('ccE').value;
  var num = exp.split("-");
  if (num[0] < 13 && num[0] > 0 && num[1] > 2011)
  return true;
  else
  {
    document.getElementById('ccE').focus();
    document.getElementById('err').innerHTML = "*Please enter card expiration date in the ##-#### format.";
    document.getElementById('err').style.visibility = 'visible';
    return false;
  }

}

function calc()
{
  var total = 0;
  if (document.getElementById('I1').checked)
  total = total + 25;
  if (document.getElementById('I2').checked)
  total = total + 500000;
  if (document.getElementById('I3').checked)
  total = total + 2300000;
  if (document.getElementById('I4').checked)
  total = total + 1000000000;

  document.getElementById('total').innerHTML = "$" + total;
}

function re()
{
  document.getElementById('fName').focus();
  document.getElementById('err').style.visibility = 'hidden';
  document.getElementById('total').innerHTML = 0;
  calc();
}
