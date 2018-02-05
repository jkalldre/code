<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:template match="studentList">
    <html>
      <head>
        <style>
          table {
          text-align:left;
          border: 1px solid black;
          }
          td, th {
          padding:5px;
          }
          th {
          background-color:lightgreen;
          }
          tr:nth-child(odd){background-color:lightgray;}
        </style>
      </head>
      <body>
        <h1>STUDENTS</h1>
        <table>
          <tr><th>First</th><th>Middle</th><th>Last</th><th>City, State</th>
          <th>College</th><th>Department</th><th>Major</th></tr>
          <xsl:apply-templates/>
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="student">
    <tr>
      <xsl:apply-templates select="name"/>
      <xsl:apply-templates select="location"/>
      <xsl:apply-templates select="college"/>
    </tr>
  </xsl:template>

  <xsl:template match="name">
    <td><xsl:value-of select="first"/></td>
    <td><xsl:value-of select="middle"/></td>
    <td><xsl:value-of select="last"/></td>
  </xsl:template>

  <xsl:template match="location">
    <td><xsl:value-of select="city"/>, <xsl:value-of select="state"/></td>
  </xsl:template>

  <xsl:template match="college">
    <td><xsl:value-of select="@name"/></td>
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="department">
    <td><xsl:value-of select="@name"/></td>
    <td><xsl:value-of select="major"/></td>
  </xsl:template>
</xsl:stylesheet>
<!--
<!ELEMENT studentList (student+)>
<!ELEMENT student (name, location, college?)>
<!ELEMENT  name (first, middle?, last)>
<!ELEMENT  first (#PCDATA)>
<!ELEMENT  middle (#PCDATA)>
<!ELEMENT  last (#PCDATA)>
<!ELEMENT  location (city,state)>
<!ELEMENT  city (#PCDATA)>
<!ELEMENT  state (#PCDATA)>
<!ELEMENT college (department?)>
<!ELEMENT department (major*)>
<!ELEMENT  major (#PCDATA)>

<!ATTLIST college name CDATA #IMPLIED>
<!ATTLIST department name CDATA "#REQUIRED">
<!ATTLIST  major id CDATA "399">
-->
