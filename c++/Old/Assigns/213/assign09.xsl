<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:template match="studentList">
    <html>
      <head>
        <style>
          p{
          white-space:pre;
          }
        </style>
      </head>
      <body>
        <h1>STUDENTS</h1>
        <xsl:apply-templates/>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="student">
    <table>
      <tr></td>
        <xsl:apply-templates select="name"/>
      </td></tr>
    <!--  <xsl:apply-templates select="location"/> -->
    </xsl:template>

    <xsl:template match="name">
        <p><xsl:value-of select="first"/> <xsl:value-of select="middle"/> <xsl:value-of select="last"/></p>
      </tr>
    </table>
  </xsl:template>

  <xsl:template match="location">

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
