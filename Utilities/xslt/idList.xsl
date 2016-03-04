<?xml version='1.0' encoding="utf-8" ?>
<xsl:stylesheet  xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version='1.0'
	             xmlns:date="http://exslt.org/dates-and-times">

<xsl:output method="text" indent="yes" encoding="utf-8"/>

<xsl:template match="/">

<xsl:for-each select="//nodes/item">
<!-- 
	<xsl:sort select="@name" order="ascending" data-type="text"/> 
-->
<xsl:call-template name="out"/>
</xsl:for-each>

<xsl:for-each select="//sensors/item">
<!--
	<xsl:sort select="@name" order="ascending" data-type="text"/>
-->
<xsl:call-template name="out"/>
</xsl:for-each>

<xsl:for-each select="//controllers/item">
<!--
	<xsl:sort select="@name" order="ascending" data-type="text"/>
-->

<xsl:call-template name="out"/>
</xsl:for-each>

<xsl:for-each select="//services/item">
<!--
	<xsl:sort select="@name" order="ascending" data-type="text"/>
-->
<xsl:call-template name="out"/>
</xsl:for-each>

<xsl:for-each select="//objects/item">
<!--
	<xsl:sort select="@name" order="ascending" data-type="text"/>
-->
<xsl:call-template name="out"/>
</xsl:for-each>

</xsl:template>

<xsl:template name="out">
<xsl:if test="normalize-space(@id)!=''">
	<xsl:value-of select="number(@id)"/><xsl:text>
	</xsl:text>
</xsl:if>
</xsl:template>

</xsl:stylesheet>
