<?xml version='1.0' encoding="utf-8" ?>
<xsl:stylesheet  xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version='1.0'
	             xmlns:date="http://exslt.org/dates-and-times">

<xsl:output method="text" indent="yes" encoding="utf-8"/>

<xsl:template match="/">
<xsl:for-each select="//messages/item">
<!--
	<xsl:sort select="@name" order="ascending" data-type="text"/>
-->
<xsl:if test="normalize-space(@id)!=''">
	<xsl:value-of select="number(@id)"/><xsl:text>
	</xsl:text>
</xsl:if>
</xsl:for-each>
</xsl:template>

</xsl:stylesheet>
