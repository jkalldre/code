<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:template match="bsa">
    <html>
      <head>
        <style>
          tr:nth-child(odd){
            text-align:center;
            background-color:lightgray;
            }
        </style>
      </head>
      <body style="white-space:pre; margin-left:5%; margin-right:5%;">
        <h2>Boy Scouts of America</h2>

        <table style="border:1px solid lightgreen;">
          <tr style="background-color:lightgreen;">
            <th style="background-color:lightgreen; padding:10px;">Council</th>
            <th style="background-color:lightgreen; padding:10px;">Troop</th>
            <th style="background-color:lightgreen; padding:10px;">First Name</th>
            <th style="background-color:lightgreen; padding:10px;">Last Name</th>
            <th style="background-color:lightgreen; padding:10px;">Merit Badges</th>
            <th style="background-color:lightgreen; padding:10px;">Rank</th>
          </tr>
          <xsl:for-each select="council">
            <xsl:for-each select="troop">
              <xsl:for-each select="scout">
                <xsl:sort select="lastName"/>
                <tr>
                  <td style="background-color:lightblue;"><xsl:value-of select="../../@name"/></td>
                  <td><xsl:value-of select="../@unitName"/></td>
                  <td><xsl:value-of select="firstName"/></td>
                  <td><xsl:value-of select="lastName"/></td>
                  <td><select style="width:15em;"><xsl:for-each select="meritBadge">
                    <option><xsl:value-of select="."/> @ <xsl:value-of select="@dateEarned"/></option>
                  </xsl:for-each></select></td>
                  <td><xsl:value-of select="rank"/> @ <xsl:value-of select="rank/@dateEarned"/></td>
                </tr>
                <tr>
                  <td><xsl:value-of select="phone"/></td>
                  <td>Address: <xsl:value-of select="address/street"/></td>
                  <td><xsl:value-of select="address/city"/>, <xsl:value-of select="address/state"/></td>
                </tr>
              </xsl:for-each>
            </xsl:for-each>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
